/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

/**
* @brief returns true when reach last entry in flight table
* @return True when is the last entre of the flight table, False otherwise
*/
static bool is_last_line(unsigned int hour, unsigned int type) {
  return  hour == HOURS - 1u && type == TYPE - 1u;
}

void array_dump(DeliveryTable a) {
  for (unsigned int type = 0u; type < TYPE; ++type) {
    for (unsigned int hour = 0u; hour < HOURS; ++hour) {
      Flight f = a[type][hour];
      fprintf(stdout, "%c: flight with %u %s arrived at %u:00", f.code, f.items_amount, f.type == 0 ? "boxes" : "letters", f.hour - 1);
      if (!is_last_line(hour, type))
      {
        fprintf(stdout, "\n");
      }
    }
  }
}

unsigned int extra_space_fee_cost (DeliveryTable a) {

  unsigned int fee = 0u; 
  unsigned int sum_boxes = 0u; 
  unsigned int sum_letters = 0u;

  /*Calculo la suma total de cajas y cartas que están en el depósito*/
  for(unsigned int i=0u; i<=FEE_CLOSE_HOUR; i++){        //ES < !
      sum_boxes += a[boxes][i].items_amount;
      sum_letters += a[letters][i].items_amount;
  }

  /*Si la cantidad de cajas supera lo permitido, multiplico por su impuesto*/
  if(sum_boxes > MAX_ALLOWED_BOXES){
    fee += (sum_boxes - MAX_ALLOWED_BOXES) * BOX_PENALTY; 
  }

  /*Si la cantidad de cartas supera lo permitido, multiplico por su impuesto*/
  if(sum_letters > MAX_ALLOWED_LETTERS){
    fee += (sum_letters - MAX_ALLOWED_LETTERS) * LETTER_PENALTY; 
  }

  return fee;
}

void array_from_file(DeliveryTable array, const char *filepath) {
  FILE *file = NULL;

  file = fopen(filepath, "r");
  if (file == NULL) {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }

  char code;
  int i = 0;
  while (!feof(file) && i<HOURS/* COMPLETAR: lectura completa de todos los datos */) {
    int res = fscanf(file,"\n_%c_ ",&code/* COMPLETAR: lectura de codigo de vuelo */);
    if (res != 1) {
      fprintf(stderr, "Invalid file.\n");
      exit(EXIT_FAILURE);
    }
    /* COMPLETAR: Generar y guardar ambos Flight en el array multidimensional */
    Flight flight_boxes = flight_from_file(file,code,boxes);/* completar... */
    Flight flight_letters = flight_from_file(file,code,letters);/* completar... */

    array[boxes][flight_boxes.hour-1u] = flight_boxes;
    array[letters][flight_letters.hour-1u] = flight_letters;

    i++;
  }
}
