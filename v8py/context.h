#ifndef CONTEXT_H
#define CONTEXT_H

#include <Python.h>
#include <v8.h>

#include "pyfunction.h"

using namespace v8;

typedef struct context_c_ {
    PyObject_HEAD
    Persistent<Context> js_context;
    Persistent<Function> promise_fulfilled;
    Persistent<Function> promise_rejected;
    Persistent<Function> bind_function;
    PyObject *js_object_cache;
    PyObject *scripts;
    bool has_debugger;
    double timeout;
} context_c;
int context_type_init();

bool context_setup_timeout(Local<Context> context);
bool context_cleanup_timeout(Local<Context> context);

void context_dealloc(context_c *self);
PyObject *context_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);
PyObject *context_eval(context_c *self, PyObject *args, PyObject *kwargs);
PyObject *context_expose(context_c *self, PyObject *args, PyObject *kwargs);
PyObject *context_expose_module(context_c *self, PyObject *module);
PyObject *context_async_call(context_c *self, PyObject *args, PyObject *kwargs);
PyObject *context_bind_py_function(context_c *self, PyObject *args);
PyObject *context_gc(context_c *self);

// Embedder data slots
#define CONTEXT_OBJECT_SLOT 1
#define OBJECT_PROTOTYPE_SLOT 2
#define ERROR_PROTOTYPE_SLOT 3

Local<Object> context_get_cached_jsobject(Local<Context> context, PyObject *py_object);
void context_set_cached_jsobject(Local<Context> context, PyObject *py_object, Local<Object> object);

PyObject *context_get_current(PyObject *shit, PyObject *fuck);
PyObject *context_get_global(context_c *self, void *shit);

PyObject *context_get_timeout(context_c *self, void *shit);
int *context_set_timeout(context_c *self, PyObject *value, void *shit);

Local<Function> bind_function(context_c *self, Local<Context> context, int argc, Local<Value> argv[], Local<Function> function);
PyObject *context_getattro(context_c *self, PyObject *name);
PyObject *context_getitem(context_c *self, PyObject *name);
int context_setattro(context_c *self, PyObject *name, PyObject *value);
int context_setitem(context_c *self, PyObject *name, PyObject *value);

extern PyTypeObject context_type;

#endif
