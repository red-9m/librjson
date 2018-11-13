#include <rapidjson/document.h>
#include <rapidjson/pointer.h>
#include "librjson.h"

using namespace rapidjson;

Document gDoc;

rj_code rjson_parse(const char* json)
{
    rj_code result = RJ_OK;
    gDoc.Parse(json);

    if (gDoc.HasParseError())
        result = RJ_PARSE_ERROR;

    return result;
}

static rj_code rjson_get(Document *doc, const char* key, Value** value)
{
    rj_code result = RJ_OK;

    if (doc && !doc->HasParseError())
    {
        Pointer p(key);
        *value = GetValueByPointer(*doc, p);
        if (!(*value))
            result = RJ_KEY_NOT_FOUND;
    } else
    {
        result = RJ_PARSE_ERROR;
    }
    return result;
}

rj_code rjson_get_string(const char* key, char* value, int valueSize)
{
    Value *v = NULL;
    rj_code result = rjson_get(&gDoc, key, &v);

    if ((result == RJ_OK) && (v))
    {
        if (v->IsString())
            snprintf(value, valueSize, "%s",  v->GetString());
        else
            result = RJ_INCORRECT_TYPE;
    }

    return result;
}

rj_code rjson_get_int(const char* key, int* value)
{
    Value *v = NULL;
    rj_code result = rjson_get(&gDoc, key, &v);

    if ((result == RJ_OK) && (v))
    {
        if (v->IsInt())
            *value = v->GetInt();
        else
            result = RJ_INCORRECT_TYPE;
    }

    return result;
}

rj_code rjson_get_double(const char* key, double* value)
{
    Value *v = NULL;
    rj_code result = rjson_get(&gDoc, key, &v);

    if ((result == RJ_OK) && (v))
    {
        if (v->IsDouble())
            *value = v->GetDouble();
        else
            result = RJ_INCORRECT_TYPE;
    }

    return result;
}
