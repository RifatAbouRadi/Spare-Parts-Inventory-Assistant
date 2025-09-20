#include <stdio.h>      //  include standard input/output library (for printf, fgets)
#include <string.h>     //  include string library (for strcmp, strcspn)

#define LINE_SIZE 50    //  define the maximum size of user input (50 characters)

int main(void) {
    char line[LINE_SIZE];   //  array to store user input
    const char *parts[] = {"hydraulic pump", "PLC module", "servo motor"};  
    //  array of available spare parts, it is like the database in the flowchart 
    int part_count = 3;     //  number of parts in the inventory

    printf("Hej. Welcome to the spare parts inventory!\n");  
    //  print welcome message once at the start

    while (1) {             //  infinite loop, we keep asking until a valid part is found  because the program exits, only after the assistant affirms that a part is available.
        printf("Which part do you need? ");  
        //  prompt user for input

        if (!fgets(line, LINE_SIZE, stdin)) return 0;  
        //  i use fgets to read the whole line including spaces
        //  this is better than scanf("%s", ...) because scanf stops at the first space
        //  example: "hydraulic pump" → fgets reads the full text
        //  but scanf("%s") would only read "hydraulic"

        line[strcspn(line, "\n")] = '\0';  
        //  remove the newline '\n' added by fgets at the end of the string

        //  check if the input is one of the special queries
        if (strcmp(line, "Do you actually have any parts?") == 0 ||
            strcmp(line, "Is there anything in stock at all?") == 0) {
            printf("We have %d part(s)!\n", part_count);  
            //  print how many parts are available
            for (int i = 0; i < part_count; i++)  
                printf("%s\n", parts[i]);  
                //  print each part name on a new line
            continue;   //  go back to ask again
        }

        int found = 0;  //  flag variable to check if the part exists in inventory

        //  loop through the parts array to find a match
        for (int i = 0; i < part_count; i++) {
            if (strcmp(line, parts[i]) == 0) {  
                //  strcmp returns 0 if the strings are exactly equal
                printf("I have got %s here for you. Bye!\n", parts[i]);  
                //  if part is found → print confirmation message
                found = 1;   //  mark that we found the part
                break;       //  exit the for-loop
            }
        }

        if (found) break;  // if part was found, break the while loop → program ends

        printf("I am afraid we don't have any %s in the inventory.\n", line);  
        //  if no part matched → print error message and loop again
    }

    return 0;  //  end program successfully
}
