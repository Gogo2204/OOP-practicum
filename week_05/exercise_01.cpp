#include <iostream>

#pragma warning(disable: 4996)

namespace GlobalConstanst
{
	constexpr size_t MAX_WAFFLES = 20;
	constexpr size_t MODEL_NAME_LEN = 20;
}

class Waffle
{
private:
	char model[GlobalConstanst::MODEL_NAME_LEN + 1];
	double weight = 0.0;
	double priceForCompany = 0.0;
	double priceForClient = 0.0;
	bool isSold = false;
public:

	const char* getModel() const
	{
		return model;
	}

	double getWeight() const
	{
		return weight;
	}

	double getPriceForClient() const
	{
		return priceForClient;
	}

	double getPriceForCompany() const
	{
		return priceForCompany;
	}

	void setModel(const char* model)
	{
		if (!model)
			return;
		std::strcpy(this->model, model);
	}

	void setWeight(const double weight)
	{
		if (weight < 0.0)
			return;
		this->weight = weight;
	}

	void setPriceForClient(const double priceForClient)
	{
		if (priceForClient < 0.0)
			return;
		this->priceForClient = priceForClient;
	}

	void setPriceForCompany(const double priceForCompany)
	{
		if (priceForCompany < 0.0)
			return;
		this->priceForCompany = priceForCompany;
	}

	void setIsSold(bool isSold)
	{
		this->isSold = isSold;
	}
};

class Shop
{
private:
	Waffle waffles[GlobalConstanst::MAX_WAFFLES];
	size_t currWaffles = 0;
	double income = 0.0;
	double expences = 0.0;
public:		

	void sellWaffles(const char* model);

	void buyWaffles(const size_t buyCount, const char* model);

	size_t countWafflesByModel(const char* model);

	double getProfit();
};

void copyWaffle(Waffle& dest, const Waffle& source)
{
	dest.setModel(source.getModel());
	dest.setWeight(source.getWeight());
	dest.setPriceForClient(source.getPriceForClient());
	dest.setPriceForCompany(source.getPriceForCompany());	
}

int findIndexOfWaffle(const Waffle* waffles, const size_t size, const char* model)
{	
	for (size_t i = 0; i < size; i++)
	{
		if (!std::strcmp(waffles[i].getModel(), model))
			return i;
	}
	return -1;
}

void Shop::sellWaffles(const char* model)
{
	if (!model)
		return;
	
	unsigned waffleToRemove = findIndexOfWaffle(waffles, currWaffles, model);

	if (waffleToRemove != -1)
	{
		waffles[waffleToRemove].setIsSold(true);
		income += waffles[waffleToRemove].getPriceForClient();
		currWaffles--;
	}		
}

void Shop::buyWaffles(const size_t buyCount, const char* model)
{
	if (!model || buyCount > (GlobalConstanst::MAX_WAFFLES - currWaffles))
		return;

	unsigned wantedWaffle = findIndexOfWaffle(waffles, currWaffles, model);
	double priceForWaffle = waffles[wantedWaffle].getPriceForCompany();
	
	for (size_t i = currWaffles; i < buyCount; i++)
	{		
		expences += priceForWaffle;
		copyWaffle(waffles[i], waffles[wantedWaffle]);
		currWaffles++;
	}
}

size_t Shop::countWafflesByModel(const char* model)
{
	if (!model)
		return 0;

	size_t res = 0;
	for (size_t i = 0; i < currWaffles; i++)
	{
		if (!std::strcmp(waffles[i].getModel(), model))
			res++;
	}
	return res;
}

double Shop::getProfit()
{
	return (income - expences);
}

int main()
{

}
