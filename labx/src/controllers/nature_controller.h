#include "../interfaces/interface_nature.h"

namespace nature_lab
{
    class NatureController
    {
    public:
        static NatureController* Instance()
        {
            static NatureController instance;
            return &instance;
        }

        NatureController()
        {
            this->start();
        }

        void start()
        {
        }

        void showNature()
        {
            for (nature_lab::interface_nature*& inteface : _natureLab)
            {
                // inteface->show();
            }
        }

        inline void showNature(int indexScene)
        {
            // _natureLab.at(indexScene)->show();
        }

        inline interface_nature*& getNature(int index)
        {
            return _natureLab.at(index);
        }

    private:
        inline void addNature(nature_lab::interface_nature* nature)
        {
            this->_natureLab.push_back(nature);
        }

    private:
        std::vector<nature_lab::interface_nature*> _natureLab;
    };
}
