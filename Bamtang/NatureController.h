#include "INature.h"

#include "VectorV1Nature.h"

namespace NatureLab
{
    class NatureController
    {
    public:

        inline NatureController(){
            this->start();
        }

        inline void start() {
            this->addNature(new VectorV1Nature());
        }

        inline void showNature(){
            for (NatureLab::INature*& inteface : _natureLab)
            {
                inteface->show();
            }
        }

    private:
    
        inline void addNature(NatureLab::INature* nature){
            this->_natureLab.push_back(nature);
        }

    private:

        std::vector<NatureLab::INature*> _natureLab;

    };

}