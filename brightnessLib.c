#include <stdio.h>
#include <stdlib.h>
#include "brightnessLib.h"


int getBrightnessPercentage(char *deviceDirectory) {
  char currentBrightnessFilename[128], maxBrightnessFilename[128];
  FILE *currentBrightnessFile, *maxBrightnessFile;
  int currentBrightness, maxBrightness, currentPercentage;

  sprintf(currentBrightnessFilename, "%s/%s", deviceDirectory, "brightness");
  sprintf(maxBrightnessFilename, "%s/%s", deviceDirectory, "max_brightness");

  currentBrightnessFile = fopen(currentBrightnessFilename, "r");
  if (currentBrightnessFile == 0) {
    printf("Error opening file: %s\n", currentBrightnessFilename);
    exit(1);
  }

  maxBrightnessFile = fopen(maxBrightnessFilename, "r");
  if (maxBrightnessFile == 0) {
    printf("Error opening file: %s\n", maxBrightnessFilename);
    exit(2);
  }

  fscanf(currentBrightnessFile, "%d", &currentBrightness);
  fscanf(maxBrightnessFile, "%d", &maxBrightness);
  fclose(currentBrightnessFile);
  fclose(maxBrightnessFile);

  currentPercentage = (currentBrightness*100) / maxBrightness;
  printf("[INFO] current brightness percentage: %d\n", currentPercentage);
  return currentPercentage;
}

int setBrightnessPercentage(char *deviceDirectory, int percentage) {
  char currentBrightnessFilename[128], maxBrightnessFilename[128];
  FILE *currentBrightnessFile, *maxBrightnessFile;
  int maxBrightness, newBrightness;

  sprintf(currentBrightnessFilename, "%s/%s", deviceDirectory, "brightness");
  sprintf(maxBrightnessFilename, "%s/%s", deviceDirectory, "max_brightness");

  currentBrightnessFile = fopen(currentBrightnessFilename, "w");
  if (currentBrightnessFile == 0) {
    printf("Error opening file: %s\n", currentBrightnessFilename);
    exit(1);
  }

  maxBrightnessFile = fopen(maxBrightnessFilename, "r");
  if (maxBrightnessFile == 0) {
    printf("Error opening file: %s\n", maxBrightnessFilename);
    exit(2);
  }

  fscanf(maxBrightnessFile, "%d", &maxBrightness);
  fclose(maxBrightnessFile);

  newBrightness = (maxBrightness*percentage) / 100;
  printf("[INFO] writing brightness value: %d\n", newBrightness);
  fprintf(currentBrightnessFile, "%d", newBrightness);
  fclose(currentBrightnessFile);
  return 0;
}
