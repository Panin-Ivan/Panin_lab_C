#include "Product.h"

void Product::SetProduct(Product product) {
    this->producer.SetName(product.producer.GetName());
    this->producer.SetPhone(product.producer.GetPhone());
    this->SetNameProduct(product.GetNameProduct());
    this->SetPrice(product.GetPrice());
    this->SetQuantity(product.GetQuantity());
}
int Product::products_cntr = 0;