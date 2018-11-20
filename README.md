# libRJson ver. 0.0.1
libRJson - Simple C API library to parse a json. Wraps powerful 'Tencent/rapidjson' under the hood

# Example:
Include `#include <librjson.h>` and parse json `{ "key1" : "value1", "obj" : { "key2" : "value2" } }`

```
char val[64];
rjson_parse(json);
rjson_get_string("/obj/key2", val, 64);
printf("Value[%s]\n", val);
```

# Configure and make:
git clone https://github.com/red-9m/librjson.git
git submodule update --init
cmake .
cmake --build .

# Run sample:
> ./rjson-sample
