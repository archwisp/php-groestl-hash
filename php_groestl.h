#ifndef PHP_GROESTL_H
# define PHP_GROESTL_H

extern zend_module_entry groestl_module_entry;
# define phpext_groestl_ptr &groestl_module_entry

# ifdef PHP_WIN32
#  define PHP_GROESTL_API __declspec(dllexport)
# else
#  define PHP_GROESTL_API
# endif

# ifdef ZTS
#  include "TSRM.h"
# endif

PHP_MINIT_FUNCTION(groestl);
PHP_MSHUTDOWN_FUNCTION(groestl);
PHP_RINIT_FUNCTION(groestl);
PHP_RSHUTDOWN_FUNCTION(groestl);
PHP_MINFO_FUNCTION(groestl);

PHP_FUNCTION(groestl_hash);
PHP_FUNCTION(groestl_hash_hex);

# ifdef ZTS
#  define GROESTL_G(v) TSRMG(groestl_globals_id, zend_groestl_globals *, v)
# else
#  define GROESTL_G(v) (groestl_globals.v)
# endif

#endif
