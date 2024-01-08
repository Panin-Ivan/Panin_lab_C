#include "Order.h"

void Order::SetOrder(Order order) {
   *this = order.GetBuyer();
   *this = *(order.GetSeller());
   *this = order.GetProduct();
   SetId(order.GetId());
   SetDate(order.GetDate());
   SetQuantity(order.GetQuantity());
   SetStatus(order.GetStatus());
}
int Order::orders_cntr = 0;
Buyer Order::GetBuyer() {
	return this->Buyer::GetBuyer();
}