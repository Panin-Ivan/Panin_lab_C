#include "Order.h"

void Order::SetOrder(Order order) {
   SetBuyer(order.GetBuyer());
   SetSeller(*(order.GetSeller()));
   SetProduct(order.GetProduct());
   SetId(order.GetId());
   SetDate(order.GetDate());
   SetQuantityOrder(order.GetQuantityOrder());
   SetStatus(order.GetStatus());
}
int Order::orders_cntr = 0;