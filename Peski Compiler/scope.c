#include "scope.h"
#include "hash_table.h"

#include <stdlib.h>
#include <string.h>

struct scope {
	struct hash_table *table;
	struct scope *next;
	int num_params;
	int num_locals;
};

static struct scope *head = 0;
static int level = 0;

struct scope * scope_create()
{
	struct scope *s = malloc(sizeof(*s));
	s->table = hash_table_create(0,0);
	s->num_params = 0;
	s->num_locals = 0;
	return s;
}

void params_plus()
{
	head->num_params++;
}

int get_num_params()
{
	return head->num_params;
}

void locals_plus()
{
	head->num_locals++;
}
int get_num_locals()
{
	return head->num_locals;
}



void scope_delete(struct scope *s)
{
	if(!s) return;
	hash_table_delete(s->table);
	free(s);
}

void scope_enter()
{
	struct scope *s = scope_create();
	s->next = head;
	head = s;
	level++;
}

int scope_level()
{
	return level;
}

void scope_exit()
{
	struct scope *s = head;
	head = s->next;
	scope_delete(s);
	level--;
}

void scope_bind(char* name,struct symbol *sym)
{
	if(head) {
		hash_table_insert(head->table, name, sym);
	}
	else {
		return;
	}
}

void scope_update(char*name, struct symbol *sym)
{
	if(head) {
		hash_table_remove(head->table, name);
		hash_table_insert(head->table, name, sym);
	}
	else {
		return;
	}
}
 
void* scope_lookup_current(char* name)
{
	if(head) {
		return hash_table_lookup(head->table, name);	
	}

	else {
		return 0;
	}
}

void* scope_lookup(char* name)
{
	struct scope *s;
	void* value;

	s = head;

	while(s) {
		value = hash_table_lookup(s->table, name);
		if(value) {
			return value;
		}
		s = s->next;
	}

	return 0;	
}



