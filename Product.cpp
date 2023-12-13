#include "Product.h"

void Product::SetProduct(Product product) {
    this->SetName(product.GetName());
    this->SetPhone(product.GetPhone());
    this->SetNameProduct(product.GetNameProduct());
    this->SetPrice(product.GetPrice());
    this->SetQuantityProduct(product.GetQuantityProduct());
}
int Product::products_cntr = 0;