#pragma once

namespace NatureLab {
    class VectorV2Window : public IWindow {
    public:
        inline VectorV2Window() {
            this->init();
        }

        inline void init() override {
            this->_nature = (VectorV2Nature*&)NatureController::Instance()->getNature(1);
        }

        inline void show() override {

            this->begin("Variables");
            {
                //ImGui::Text("Variables");

                if (ImGui::ColorEdit3("Color", _nature->_colorxyz))
                {
                    _nature->setColor(_nature->_colorxyz[0], _nature->_colorxyz[1], _nature->_colorxyz[2]);
                }

                ImVec2 _mouse = this->getPositionMouseRender();
                _nature->setMouse(_mouse.x, _mouse.y);               
            }
            this->end();
        }

        inline ImVec2 getPositionMouseRender()
        {
            this->begin("Render");

            ImVec2 _displayRender = ImGui::GetWindowSize();
            ImVec2 _display = ImGui::GetCursorScreenPos();

            ImVec2 mousePosition = ImGui::GetMousePos();
            ImVec2 sceenPosition = ImGui::GetCursorScreenPos();
            ImVec2 scroll = ImVec2(ImGui::GetScrollX(), ImGui::GetScrollY());

            ImVec2 _mouse = ImVec2(mousePosition.x - sceenPosition.x - scroll.x, mousePosition.y - sceenPosition.y - scroll.y);
            _mouse.x = (_mouse.x * SceneAssets::SCREEN_WIDTH) / _displayRender.x;
            _mouse.y = SceneAssets::SCREEN_HEIGHT - SceneAssets::LIMIT_HEIGHT - (_mouse.y * SceneAssets::SCREEN_HEIGHT) / _displayRender.y;
         
            this->end();

            return _mouse;
        }

    private:

        VectorV2Nature* _nature;
    };
}