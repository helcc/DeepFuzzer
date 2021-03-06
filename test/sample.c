/*
 * Generate by Deepfuzzer
 * Target binary: lpc.o
 * Target function: int32_t check_if_constant(const int16_t *data,int32_t
 * num_elements)
 * Time: Sat Mar 30 17:11:21 CDT 2019
 */

/* Steal From source Code */

#include "lpc.h"
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

/* Generate by deepfuzzer */
#include <inttypes.h>

int main(int argc, char **argv) {
    FILE *infile = fopen(argv[1], "rb");

    fseek(infile, 0, SEEK_END);
    int fileSize = (int)ftell(infile);
    rewind(infile);

    int pointer_size = 1;
    if (fileSize < sizeof(uint16_t) * pointer_size) {
        fclose(infile);
        return 0;
    }

    uint16_t d1_data;
    fread(&d1_data, sizeof(uint16_t), 1, infile);

    int minSize = sizeof(uint16_t) * pointer_size +
                  sizeof(const int16_t) * d1_data + sizeof(int32_t);
    if (minSize > fileSize) {
        fclose(infile);
        return 0;
    }

    int16_t reference_data[d1_data];
    for (long int i = 0; i < d1_data; ++i) {
        int16_t tmp;
        fread(&tmp, sizeof(int16_t), 1, infile);
        reference_data[i] = tmp;
    }
    const int16_t *data = reference_data;

    int32_t num_elements;
    fread(&num_elements, sizeof(int32_t), 1, infile);

    fclose(infile);

    /* Fuzzing Target*/
    check_if_constant(data, num_elements);

    return 0;
}
