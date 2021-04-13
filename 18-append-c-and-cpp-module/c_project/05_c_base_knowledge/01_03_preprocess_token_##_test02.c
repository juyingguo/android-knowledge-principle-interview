#include <stdio.h>
void quit_command(){
    printf("I am quit command\n");
}
void help_command(){
    printf("I am help command\n");
}
struct command
{
    char * name;
    void (*function) (void);
};
#define COMMAND(NAME) {#NAME,NAME##_command}
#define PRINT(NAME) printf("token"#NAME"=%d\n", token##NAME)
main(){
    int token9=9;
    PRINT(9);
    struct command commands[] = {
        COMMAND(quit),
        COMMAND(help),
    };
    commands[0].function();
}
