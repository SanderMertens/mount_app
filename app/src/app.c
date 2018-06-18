#include <include/app.h>

/*
- Write an application that queries for data
- Create a boilerplate mount class (doesnt provide any data)
  - constructor
  - on_query
    - prints query to console

- configure the app with the mount
  - should be able to see the query

- replace on_query implementation with code that calls remote API
*/

int cortomain(int argc, char *argv[]) {
    printf("app loaded\n");

    corto_create(data_o, "foo", corto_int32_o);

    corto_iter it;
    corto_select("*").from("data").iter(&it);

    while (corto_iter_hasNext(&it)) {
        corto_result *r = corto_iter_next(&it);
        corto_info("received object '%s' => %s",
            r->id,
            corto_result_getText(r));
    }

    return 0;
}
