#ifndef TORREARQUERA_H
#define TORREARQUERA_H
#include "Defensa.h"
class TorreArquera : public Defensa {
public:
    TorreArquera();
    explicit TorreArquera(int id);
    void atacar() override;
    std::string getTipo() const override;
    void dispararRapido();
};
#endif
