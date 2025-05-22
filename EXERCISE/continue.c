#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[50];
    char author[50];
    float price;
};

int main() {
    struct Book B;
    FILE *file;

    printf("Enter book title: ");
    fgets(B.title, sizeof(B.title), stdin);

    printf("Enter author name: ");
    fgets(B.author, sizeof(B.author), stdin);

    printf("Enter price: ");
    scanf("%f", &B.price);

    file = fopen("book.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "%s%s%.1f\n", B.title, B.author, B.price);
    fclose(file);

    file = fopen("book.txt", "r");
    if (file == NULL) {
        printf("Error reading file!\n");
        return 1;
    }

    printf("\nSaved Book Details:\n");

    fgets(B.title, sizeof(B.title), file);
    fgets(B.author, sizeof(B.author), file);
    fscanf(file, "%f", &B.price);

    printf("Title: %s", B.title);
    printf("Author: %s", B.author);
    printf("Price: %.0f shs\n", B.price);

    fclose(file);
    return 0;
}
