#ifndef LPF_H_
#define LPF_H_

#include "Arduino.h"

typedef struct Struct_LowPassFilter {
  bool    Init_Filter;
  int16_t CutOffFreq;
  float   BFilter[3];
  float   AFilter[3];
  int64_t B_64_Bits[3];
  int64_t A_64_Bits[3];
  int16_t Coefficient_Bit_Shift;
  int16_t Input_Bit_Shift;
  int32_t Input_Bias;
  int32_t X_32Bits[3];
  int32_t Y_32Bits[3];
} Struct_LowPassFilter;

void    LowPassFilterCoefficient(int16_t CutOffFreq, Struct_LowPassFilter *Filter, int16_t InputBias);
int32_t LowPassFilter(Struct_LowPassFilter *Filter, int32_t Input_Device, int16_t CutOffFreq, int16_t InputBiasSet);
#endif
