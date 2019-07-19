#include <Python.h>

#include "trivechain.h"

static PyObject *trivechain_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    trivechain_hash((char *)PyBytes_AsString((PyObject*) input), (int)PyBytes_Size((PyObject*) input), output);
#else
    trivechain_hash((char *)PyString_AsString((PyObject*) input), (int)PyString_Size((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef TrivechainMethods[] = {
    { "getPoWHash", trivechain_getpowhash, METH_VARARGS, "Returns the proof of work hash using trivechain hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef TrivechainModule = {
    PyModuleDef_HEAD_INIT,
    "trivechain_hash",
    "...",
    -1,
    TrivechainMethods
};

PyMODINIT_FUNC PyInit_trivechain_hash(void) {
    return PyModule_Create(&TrivechainModule);
}

#else

PyMODINIT_FUNC inittrivechain_hash(void) {
    (void) Py_InitModule("trivechain_hash", TrivechainMethods);
}
#endif
