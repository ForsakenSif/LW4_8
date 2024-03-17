#include <iostream>
#include <string>

class Place {
protected:
    std::string name;
    int population;

public:
    Place(const std::string& name, int population) : name(name), population(population) {}
    virtual ~Place() {}

    virtual void view() const = 0; // Виртуальный метод просмотра текущего состояния
    virtual void reset(int newPopulation) = 0; // Виртуальный метод переустановки текущего состояния
};

class Region : public Place {
protected:
    std::string governor;

public:
    Region(const std::string& name, int population, const std::string& governor)
        : Place(name, population), governor(governor) {}

    ~Region() override {}

    void view() const override {
        std::cout << "Region: " << name << ", Population: " << population << ", Governor: " << governor << std::endl;
    }

    void reset(int newPopulation) override {
        population = newPopulation;
    }
};

class City : public Region {
protected:
    int area;

public:
    City(const std::string& name, int population, const std::string& governor, int area)
        : Region(name, population, governor), area(area) {}

    ~City() override {}

    void view() const override {
        std::cout << "City: " << name << ", Population: " << population << ", Governor: " << governor << ", Area: " << area << std::endl;
    }

    void reset(int newPopulation) override {
        population = newPopulation;
    }
};

class Metropolis : public City {
private:
    bool isGlobal;

public:
    Metropolis(const std::string& name, int population, const std::string& governor, int area, bool isGlobal)
        : City(name, population, governor, area), isGlobal(isGlobal) {}

    ~Metropolis() override {}

    void view() const override {
        std::cout << "Metropolis: " << name << ", Population: " << population << ", Governor: " << governor << ", Area: " << area;
        if (isGlobal) std::cout << ", Global Metropolis";
        std::cout << std::endl;
    }

    void reset(int newPopulation) override {
        population = newPopulation;
    }
};

int main() {
    Metropolis newYork("New York", 8500000, "Bill de Blasio", 468.9, true);
    newYork.view();

    newYork.reset(9000000);
    newYork.view();

    return 0;
}
