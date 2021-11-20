/**
 * @file QuantumRand.h
 * @author Aleksandar Damnjanovic (https://www.linkedin.com/in/aleksandar-damnjanovic-9a77721b1/)
 * @date 2021-11-20
 */

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>
#include <unistd.h>

char* raw;
u_int64_t value=-1;

size_t receiver_funct(char* buffer, size_t itemSize,
size_t numItems, void* ignore){
    if(raw!=NULL)
        free(raw);
    raw= (char*)malloc(sizeof(char) * strlen(buffer));
    memset(raw,'\0', sizeof(char) * strlen(buffer));
    strcpy(raw, buffer);
    return itemSize * numItems;
}

uint64_t QuantumRand_next(){
    char address[]={"https://qrng.anu.edu.au/API/jsonI.php?length=1&type=hex16&size=8"};
    CURL *curl= curl_easy_init();
    CURLcode code;

    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, address);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, receiver_funct);

        code= curl_easy_perform(curl);
        if(code!=CURLE_OK){
            curl_easy_cleanup(curl);
            return -1;
        }

    }

    struct json_object *document;
    struct json_object *valueJson;
    document= json_tokener_parse(raw);
    json_object_object_get_ex(document,"data", &valueJson);
    char val[19];
    memset(val,'\0', 19);
    sprintf(val,"0x%s\0", json_object_get_string(json_object_array_get_idx(valueJson,0)));

    u_int64_t number = (uint64_t)strtol(val, NULL, 16);
    curl= NULL;

    if(number==LONG_MAX)
        number=QuantumRand_next();

    value= number;
    return number;

}

uint64_t QuantumRand_next_min(int min){
    u_int64_t ret= value;
    if(ret<min)
        ret= ret+(LONG_MAX-min);

    return ret;
}

uint64_t QuantumRand_next_max(int max){
    u_int64_t ret= value;
    if(ret>max)
        ret= ret % max;

    return ret;
}

uint64_t QuantumRand_next_min_max(int min, int max){
    u_int64_t ret= QuantumRand_next_max(max);
    if(ret<min && min!=0)
        ret= min+(ret % (max-min));

    return ret;
}

float QuantumRand_get_float(){
    float f=-1;
    if(value<LONG_MAX)
        f= (float)((float)value / (float)LONG_MAX);
    else
        f= (float)((float)LONG_MAX / (float)value);

    return f;
}