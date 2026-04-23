#include "objects.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Car *car_create(char *brand, char *model, char *license){

    Car* p = malloc(sizeof(Car));
    p -> brand = brand;
    p -> model = model;
    p -> license = license;

    return p;
}

Customer *customer_create(char *name, char *address){

    Customer* p = malloc(sizeof(Customer));
    p -> name = name;
    p -> address = address;

    return p;
}

Registry *registry_create(Customer **customers, int size){

    Registry* p = malloc(sizeof(Registry));
    p-> customers = customers;
    p->size = size;

    return p;
}

void car_destroy(Car *car){

    if (car == NULL){
        return;
    }

    else{   

        free(car);
    }

}

void customer_destroy(Customer *customer){

    if (customer == NULL){
        return;
    }

    else{

        free(customer);
    }
}

void registry_destroy(Registry *registry){

    if (registry == NULL){
        return;
    }

    else{
    
        free(registry);

    }
}

void link_car(Car *car, Customer *customer){

    if(car == NULL || customer == NULL){
        return;
    }

    else {
        customer -> car = car;
        car -> customer = customer;
    }

}

void print_registry(Registry *registry){

    if (registry == NULL){
        return;
    }

    for(int i = 0; i < registry->size; i++){

        printf("=====\nNom : %s\tAdresse : %s\tMarque : %s\tModèle : %s\tImmatriculation : %s\n=====\n", registry->customers[i]->name, registry->customers[i]->address, registry->customers[i]->car->brand, registry->customers[i]->car->model, registry->customers[i]->car->license);
    }

}