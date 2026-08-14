#include <stdio.h>
#include <string.h>


void new_cmd(void) {
    printf("Hello new_cmd\n");
}

void open_cmd(void) {
    printf("Hello open_cmd\n");
}

void close_cmd(void) {
    printf("Hello close_cmd\n");
}

void close_all_cmd(void) {
    printf("Hello close_all_cmd\n");
}

void save_cmd(void) {
    printf("Hello save_cmd\n");
}

void save_as_cmd(void) {
    printf("Hello save_as_cmd\n");
}

void save_all_cmd(void) {
    printf("Hello save_all_cmd\n");
}

void print_cmd(void) {
    printf("Hello print_cmd\n");
}

void exit_cmd(void) {
    printf("Hello exit_cmd\n");
}

	struct {
		char *cmd_name;
		void (*cmd_pointer) (void);
	} file_cmd[] = 
	{{"new",		new_cmd},
	 {"open",		open_cmd},
	 {"close",		close_cmd},
	 {"close all",	close_all_cmd},
	 {"save",		save_cmd},
	 {"save as",	save_as_cmd},
	 {"save all",	save_all_cmd},
	 {"print",		print_cmd},
	 {"exit",		exit_cmd}
	
	};

void run_fun(char *s);
int main(void) {
    
    int n = sizeof(file_cmd) / sizeof(file_cmd[0]);
    run_fun("new");
    return 0;
}

void run_fun(char *s) {
    int n = sizeof(file_cmd) / sizeof(file_cmd[0]);

    for (int i = 0; i < n; i++) {
        if (strcmp(s, file_cmd[i].cmd_name) == 0) {
            file_cmd[i].cmd_pointer();
        }
    }
}



