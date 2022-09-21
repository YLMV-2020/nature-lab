#include "../interfaces/INature.h"

namespace labx
{
    class NatureController
    {
    public:

        static NatureController* Instance(){
            static NatureController instance;
            return &instance;
        }

        inline NatureController(){



            this->start();
        }

        inline void start() {

        }

        inline void showNature(){
            for (labx::INature*& inteface : _natureLab)
            {
                inteface->show();
            }
        }

        inline void showNature(int indexScene) {
            _natureLab.at(indexScene)->show();
        }

        inline INature*& getNature(int index)
        {
            return _natureLab.at(index);
        }

    private:
    
        inline void addNature(labx::INature* nature){
            this->_natureLab.push_back(nature);
        }

    private:

        std::vector<labx::INature*> _natureLab;

    };

}