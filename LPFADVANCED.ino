#include "LPF.h"

/******************************INFO**********************************/
//AUTOR:JULIO CESAR MATIAS
//DESENVOLVIDO OFICIALMENTE PARA A CONTROLADORA DE VOO JCFLIGHT
//DATA:ABRIL DE 2020
/********************************************************************/

//#define FREQ_CUTOFF  400  //400HZ DE CORTE PARA SERVOS
//#define BIAS_ADJ     1500 //1500 VALOR DE AJUSTE DE BIAS PARA SERVOS,PONTO MEDIO ENTRE 1000uS - 2000uS

#define FREQ_CUTOFF  20  //20HZ DE CORTE PARA ENTRADAS ANALOGICAS
#define BIAS_ADJ     512 //512 VALOR DE AJUSTE DE BIAS PARA ENTRADAS ANALOGICAS 2^10 / 2 = 512

Struct_LowPassFilter LPFDevice; //CRIA A INSTANCIA PARA O DISPOSITIVO

int32_t DeviceToFilter; //ENTRADA DO DISPOSITIVO
int32_t DeviceFiltered; //SAIDA FILTRADA DO DISPOSITIVO

void setup() {
  Serial.begin(115200);
}

void loop() {
  DeviceToFilter = analogRead(0);
  DeviceFiltered = LowPassFilter(&LPFDevice, DeviceToFilter, FREQ_CUTOFF, BIAS_ADJ);
  SerialPrint_P("NotFiltered:", DeviceToFilter, "OutputFiltered:", DeviceFiltered);
  delay(30);
}

void SerialPrint_P(const char *Text1, int32_t Value1, const char *Text2, int32_t Value2) {
  Serial.print(Text1);
  Serial.print(Value1);
  Serial.print("\t");
  Serial.print(Text2);
  Serial.print(Value2);
  Serial.println();
}
