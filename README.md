# libRJson ver. 0.0.1
libRJson - Simple C API library to parse a json. Wraps powerful 'Tencent/rapidjson' under the hood

# Example:
```
#include <librjson.h>

...

const char *json = "{ \"my_key\" : \"my_value\" }";
rjson_parse(json);

char val[64];
rjson_get_string("/my_key", val, 64);
printf("Value[%s]\n", val);
```

# Configure and make:
git clone https://github.com/red-9m/librjson.git
git submodule update --init
cmake .

# Compile library:
cmake --build .

# Clean:
./clean-dir

# Run sample:
> ./rjson-sample
