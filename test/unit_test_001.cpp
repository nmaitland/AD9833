//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2023-08-27
// PURPOSE: unit tests for the AD9833 function generator
//          https://github.com/RobTillaart/AD9833
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)

#include <ArduinoUnitTests.h>

#include "Arduino.h"
#include "AD9833.h"


unittest_setup()
{
  fprintf(stderr, "AD9833_LIB_VERSION: %s\n", AD9833_LIB_VERSION);
}


unittest_teardown()
{
}


unittest(test_constants)
{
  assertEqual(12500000UL, AD9833_MAX_FREQ);
  assertEqual(360, AD9833_MAX_PHASE);

  assertEqual(0, AD9833_OFF);
  assertEqual(1, AD9833_SINE);
  assertEqual(2, AD9833_SQUARE1);
  assertEqual(3, AD9833_SQUARE2);
  assertEqual(4, AD9833_TRIANGLE);
}


unittest(test_constructor)
{
  AD9833 funcgen;
  AD9833 fgsw;

  funcgen.begin(10);
  fgsw.begin(4,5,6);

  assertEqual(AD9833_MAX_FREQ, funcgen.getMaxFrequency());
  assertEqual(AD9833_MAX_PHASE, funcgen.getMaxPhase());

  assertTrue(funcgen.usesHWSPI());
  assertFalse(fgsw.usesHWSPI());
}


unittest(test_wave)
{
  AD9833 funcgen;
  funcgen.begin(4, 5, 6);

  for (long wave = 0; wave < 5; wave++)
  {
    funcgen.setWave(wave);
    int w = funcgen.getWave();
    assertEqual(w, wave);
  }
}


unittest(test_frequency)
{
  AD9833 funcgen;
  funcgen.begin(4, 5, 6);

  for (long freq = 0; freq < 10000000; freq += 1000000)
  {
    funcgen.setFrequency(freq);
    long fr = funcgen.getFrequency();
    assertEqual(fr, freq);
  }
}


unittest(test_phase)
{
  AD9833 funcgen;
  funcgen.begin(4, 5, 6);

  for (int ph = 0; ph < 360; ph += 30)
  {
    funcgen.setPhase(ph);
    int phase = funcgen.getPhase();
    assertEqual(ph, phase);
  }
}


unittest_main()


//  -- END OF FILE --


