#include <stdio.h>
#include <stdlib.h>

// Function to calculate the total sales
float totalSale(float sales[], int n) {
    float total = 0.0;
    for (int i = 0; i < n; i++) {
        total += sales[i];
    }
    return total;
}

// Function to find the maximum sale value
float maxSale(float sales[], int n) {
    if (n <= 0) {
        return 0.0; // Handle the case of an empty array
    }
    float max_val = sales[0];
    for (int i = 1; i < n; i++) {
        if (sales[i] > max_val) {
            max_val = sales[i];
        }
    }
    return max_val;
}

int main() {
    FILE *file;
    // CORRECTED: Use double backslashes or forward slashes for the file path
    char filename[] = "C:\\Users\\pacom\\OneDrive\\Escritorio\\Data Structures\\txt\\Sales_2.txt";
    int count = 0;
    char ch;

    // Open the file to count the number of lines
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Count the lines (sales values) in the file
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    // Correct for the last line that might not have a newline character
    if (fseek(file, 0, SEEK_END) == 0 && ftell(file) > 0 && fgetc(file) != '\n' && count > 0) {
        count++;
    }

    // Rewind the file pointer to the beginning
    rewind(file);

    // Dynamically allocate memory for the array of sales
    float *sales_array = (float *)malloc(count * sizeof(float));
    if (sales_array == NULL) {
        printf("Error: Memory allocation failed!\n");
        fclose(file);
        return 1;
    }
    // Read sales values into the dynamically allocated array
    for (int i = 0; i < count; i++) {
        if (fscanf(file, "%f", &sales_array[i]) != 1) {
            printf("Error: Failed to read a floating-point number from the file.\n");
            free(sales_array);
            fclose(file);
            return 1;
        }
    }

    // Close the file
    fclose(file);

    // Calculate and print the total sales
    float total = totalSale(sales_array, count);
    printf("Total sales: %.2f\n", total);

    // Calculate and print the maximum sales value
    float max = maxSale(sales_array, count);
    printf("Maximum sale: %.2f\n", max);

    // Free the dynamically allocated memory
    free(sales_array);

    return 0;
}