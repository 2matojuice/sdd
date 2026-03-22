#include <stdio.h>
#include "../../lib/objects/objects.h"

int main()
{

    Customer *customer1 = customer_create("John", "12 Rue de La Chapelle"); 
    Car *car1 = car_create("Golf", "6", "566435466");
    
    Customer *customers[] = {customer1};
    Registry *registry1 = registry_create(customers, 1);

    link_car(car1, customer1);
    print_registry(registry1);

    car_destroy(car1);
    customer_destroy(customer1);
    registry_destroy(registry1);

    return 0;
}
