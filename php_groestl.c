#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "ext/standard/basic_functions.h"
#include "Groestl-opt.h"
#include "php_groestl.h"

#define GROESTL_DEFAULT_BIT_LENGTH 512

zend_function_entry groestl_functions[] = {
	PHP_FE(groestl_hash, NULL)
	{NULL, NULL, NULL}
};

zend_module_entry groestl_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"groestl",
	groestl_functions,
	PHP_MINIT(groestl),
	PHP_MSHUTDOWN(groestl),
	NULL,
	NULL,
	PHP_MINFO(groestl),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1",
#endif
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_GROESTL
ZEND_GET_MODULE(groestl)
#endif

PHP_MINIT_FUNCTION(groestl)
{
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(groestl)
{
	return SUCCESS;
}

PHP_MINFO_FUNCTION(groestl)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "groestl hash support", "enabled");
	php_info_print_table_end();
}

PHP_FUNCTION(groestl_hash)
{
   char hash[64];
   char *buffer = NULL;
   int buffer_size;
   long hash_bit_length = GROESTL_DEFAULT_BIT_LENGTH;

   if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|l",
            &buffer, &buffer_size, &hash_bit_length) == FAILURE) 
   {
      RETURN_FALSE;
   }
  
   HashReturn result;

   if ((result = Hash((size_t) hash_bit_length, buffer, buffer_size, hash)) != HASH_SUCCESS)
   {
      if (result == BAD_HASHLEN)
      {
         php_error_docref(NULL TSRMLS_CC, E_WARNING, "Bad bit-length");
      }

      RETURN_FALSE;
   }

   RETURN_STRINGL(hash, ceil(hash_bit_length / 8), 1);
}
