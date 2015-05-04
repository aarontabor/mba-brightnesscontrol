#include <stdio.h>
#include <stdlib.h>
#include "brightnessLib.h"


int readInteger(char *filename);
void writeInteger(char *filename, int value);

int getBrightnessPercentage(char *deviceDirectory) {
  char currentBrightnessFilename[128], maxBrightnessFilename[128];
  int currentBrightness, maxBrightness, currentPercentage;

  sprintf(currentBrightnessFilename, "%s/%s", deviceDirectory, "brightness");
  sprintf(maxBrightnessFilename, "%s/%s", deviceDirectory, "max_brightness");

  currentBrightness = readInteger(currentBrightnessFilename);
  maxBrightness = readInteger(maxBrightnessFilename);

  currentPercentage = (currentBrightness*100) / maxBrightness;
  printf("[INFO] current brightness percentage: %d\n", currentPercentage);
  return currentPercentage;
}

int setBrightnessPercentage(char *deviceDirectory, int percentage) {
  char currentBrightnessFilename[128], maxBrightnessFilename[128];
  int maxBrightness, newBrightness;

  sprintf(currentBrightnessFilename, "%s/%s", deviceDirectory, "brightness");
  sprintf(maxBrightnessFilename, "%s/%s", deviceDirectory, "max_brightness");

  maxBrightness = readInteger(maxBrightnessFilename);

  newBrightness = (maxBrightness*percentage) / 100;
  printf("[INFO] writing brightness value: %d\n", newBrightness);
  writeInteger(currentBrightnessFilename, newBrightness);
  return 0;
}

int readInteger(char *filename) {
  FILE *file;
  int value;

  file = fopen(filename, "r");
  if (file == 0) {
    printf("Error opening file: %s\n", filename);
    exit(1);
  }
  fscanf(file, "%d", &value);
  fclose(file);
  return value;
}

void writeInteger(char *filename, int value) {
  FILE *file;

  file = fopen(filename, "w");
  if (file == 0) {
    printf("Error opening file: %s\n", filename);
    exit(1);
  }
  fprintf(file, "%d", value);
  fclose(file);
}
