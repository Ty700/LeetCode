int calPoints(char** operations, int operationsSize) {
    int32_t sum = 0;
    int32_t* record = malloc(sizeof(*record) * operationsSize);
    int sizeOfRecord = 0;   

    for(int i = 0; i < operationsSize; i++){
        if (strcmp(operations[i], "+") == 0) {
        // New Score = last two records added together
            if (sizeOfRecord >= 2) {
                record[sizeOfRecord] = record[sizeOfRecord - 1] + record[sizeOfRecord - 2];
                sum += record[sizeOfRecord];
                sizeOfRecord += 1;
            }
        } else if (strcmp(operations[i], "D") == 0) {
            // Double the last valid score
            if (sizeOfRecord > 0) {
                record[sizeOfRecord] = record[sizeOfRecord - 1] * 2;
                sum += record[sizeOfRecord];
                sizeOfRecord += 1;
            }
        } else if (strcmp(operations[i], "C") == 0) {
            // Remove the last valid score
            if (sizeOfRecord > 0) {
                sum -= record[sizeOfRecord - 1];
                sizeOfRecord -= 1;
            }
        } else {
            // Assign a new score
            record[sizeOfRecord] = atoi(operations[i]);
            sum += record[sizeOfRecord];
            sizeOfRecord += 1;
        }

    }

    return sum;
}