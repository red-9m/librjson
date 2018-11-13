#ifndef _LIB_RJSON_H_
#define _LIB_RJSON_H_

#ifdef __cplusplus
    #define RJ_EXTERN extern "C"
#else
    #define RJ_EXTERN extern
#endif

enum rj_code
{
    RJ_OK = 0,
    RJ_PARSE_ERROR,
    RJ_KEY_NOT_FOUND,
    RJ_INCORRECT_TYPE,
};

RJ_EXTERN enum rj_code rjson_parse(const char* json);

RJ_EXTERN enum rj_code rjson_get_string(const char* key, char* value, int valueSize);

RJ_EXTERN enum rj_code rjson_get_int(const char* key, int* value);

RJ_EXTERN enum rj_code rjson_get_double(const char* key, double* value);

#endif
