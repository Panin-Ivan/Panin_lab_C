#include "Order.h"

void Order::SetOrder(Order order) {
   SetBuyer(order.GetBuyer());
   SetSeller(*(order.GetSeller()));
   SetProduct(order.GetProduct());
   SetId(order.GetId());
   SetDate(order.GetDate());
   SetQuantity(order.GetQuantity());
   SetStatus(order.GetStatus());
}
int Order::orders_cntr = 0;
void Order::OutBuyer() {
	cout << "���:" << this->Buyer::GetName() << "  �������:" << this->Buyer::GetPhone() << endl;
}