#include <stdio.h>
#include "librjson.h"

int main(void)
{
    const char *json = "{ \"project\" : \"RapidJSON\", \"stars\" : 11, \"a\" : { \"b\" : 12345, \"foo\" : [\"bar\", \"baz\"] }, \"hello\" : \"world\" }";
    if (rjson_parse(json) == RJ_OK)
    {
        const int VAL_SIZE = 1024;
        char val[VAL_SIZE];
        int val_int;

        // Print string from array
        if (rjson_get_string("/a/foo/0", val, VAL_SIZE) == RJ_OK)
            printf("a->foo[0]:[%s]\n", val);

        // Print int
        if (rjson_get_int("/stars", &val_int) == RJ_OK)
            printf("stars:[%d]\n", val_int);

        // Error cases
        enum rj_code res_incorrect_type = rjson_get_int("/a/foo/0", &val_int);
        enum rj_code res_key_not_found = rjson_get_int("/nothing", &val_int);
        printf("Error codes: err_type[%d] err_key[%d]\n", res_incorrect_type, res_key_not_found);
    }

    return 0;
}
