from distutils.core import setup, Extension

trivechain_hash_module = Extension('trivechain_hash',
                                 sources = ['trivechainmodule.c',
                                            'trivechain.c',
                                            'sha3/blake.c',
                                            'sha3/bmw.c',
                                            'sha3/groestl.c',
                                            'sha3/jh.c',
                                            'sha3/keccak.c',
                                            'sha3/skein.c',
                                            'sha3/cubehash.c',
                                            'sha3/echo.c',
                                            'sha3/luffa.c',
                                            'sha3/simd.c',
                                            'sha3/shavite.c'],
                               include_dirs=['.', './sha3'])

setup (name = 'trivechain_hash',
       version = '1.3.1',
       description = 'Binding for Trivechain X16R proof of work hashing.',
       ext_modules = [trivechain_hash_module])
