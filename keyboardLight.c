#include <stdio.h>


#define brightnessDirectory "/sys/class/leds/smc::kbd_backlight"
#define INCREMENT_VALUE 10


int doIncrement(int currentBrightnessPercentage);
int doDecrement(int currentBrightnessPercentage);
int setBrightnessPercentage(char *directory, int percentage);

int main(int argc, char *argv[]) {
  int brightnessPercentage = getBrightnessPercentage(brightnessDirectory);

  char *option = argv[1];
  if (strcmp(option, "--increment") == 0) {
    doIncrement(brightnessPercentage);
  } else if (strcmp(option, "--decrement") == 0) {
    doDecrement(brightnessPercentage);
  } else if (strcmp(option, "--set") == 0) {
    int newPercentage = atoi(argv[2]);
    setBrightnessPercentage(brightnessDirectory, newPercentage);
  } else {
    printf("Uasge: keyboardLight <option> [brightness-percentage]\n");
  }

  return 0;
}

int doIncrement(int currentBrightnessPercentage) {
  int newPercentage = currentBrightnessPercentage + INCREMENT_VALUE;
  setBrightnessPercentage(brightnessDirectory, (newPercentage > 100) ? 100 : newPercentage);
  return 0;
}

int doDecrement(int currentBrightnessPercentage) {
  int newPercentage = currentBrightnessPercentage - INCREMENT_VALUE;
  setBrightnessPercentage(brightnessDirectory, (newPercentage < 0) ? 0 : newPercentage);
  return 0;
}
