#ifndef SCOPE_H
#define SCOPE_H

#include "hash_table.h"
#include "symbol.h"

void scope_enter();

void scope_exit();

int scope_level();

void scope_bind(char* name,struct symbol *sym);

void* scope_lookup(char* name);

void* scope_lookup_current(char* name);

int get_num_params();

void params_plus();

int get_num_locals();

void locals_plus();

#endif
