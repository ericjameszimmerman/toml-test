#include <stdio.h>
#include <stdlib.h>
#include "toml-c.h"

int main() {
    FILE* fp;
    char errbuf[200];

    // Open the TOML file
    if (!(fp = fopen("config.toml", "r"))) {
        perror("Can't open file");
        return 1;
    }

    // Parse the TOML file
    toml_table_t* conf = toml_parse_file(fp, errbuf, sizeof(errbuf));
    fclose(fp);
    if (!conf) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    // Get 'title' value
    toml_value_t title = toml_table_string(conf, "title");
    if (title.ok) {
        printf("Title: %s\n", title.u.s);
    } else {
        printf("No title found.\n");
    }

    // Get nested 'owner' table
    toml_table_t* owner = toml_table_table(conf, "owner");
    if (owner) {
        // Get 'name' value within 'owner' table
        toml_value_t name = toml_table_string(owner, "name");
        if (name.ok) {
            printf("Owner Name: %s\n", name.u.s);
        } else {
            printf("No owner name found.\n");
        }
    } else {
        printf("No owner found.\n");
    }

    toml_free(conf);
    return 0;
}
