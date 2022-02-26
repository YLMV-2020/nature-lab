#pragma once

namespace NatureLab {

    struct ForceV4System
    {
        Math::Vector2 m_position;
        Math::Vector2 m_velocity;
        Math::Vector2 m_acceleration;
        float m_mass;

        inline ForceV4System() {
            this->m_position = Math::Vector2(450, 350);
            this->m_velocity = Math::Vector2(0.01f, 0.01f);
            this->m_acceleration = Math::Vector2(0.01f, 0.01f);
            this->m_mass = 10.0f;
        }

        inline ForceV4System(float mass, Math::Vector2 position = Math::Vector2(50, 600)) {
            this->m_position = position;
            this->m_velocity = Math::Vector2(0.01f, 0.01f);
            this->m_acceleration = Math::Vector2(0.01f, 0.01f);
            this->m_mass = mass;
        }

        inline void update(const int& _width, const int& _height, float m_limiteEdge = 0) {
            m_velocity = m_velocity + m_acceleration;
            m_position = m_position + m_velocity;
            m_acceleration = m_acceleration * 0.0f;

            this->checkEdges(_width, _height, m_limiteEdge);
        }

        inline void applyForce(Math::Vector2 force) {
            m_acceleration = m_acceleration + (force / m_mass);
        }

        inline void checkEdges(const int& _width, const int& _height, float m_limiteEdge = 0) {

            if (m_position.x > _width + m_limiteEdge) {
                m_position.x = _width + m_limiteEdge;
                m_velocity.x *= -1;
            }
            else if (m_position.x < 0 - m_limiteEdge) {
                m_velocity.x *= -1;
                m_position.x = 0 - m_limiteEdge;
            }
            if (m_position.y > _height + m_limiteEdge) {
                m_velocity.y *= -1;
                m_position.y = _height + m_limiteEdge;
            }
            else if (m_position.y < 0 - m_limiteEdge) {
                m_velocity.y *= -1;
                m_position.y = 0 - m_limiteEdge;
            }
        }

    };

    struct AttractorForceV4 {
        Math::Vector2 m_position;
        float m_mass;
        float m_gravity;
        Math::Vector2 m_dragOffset;
        bool m_dragging;
        bool m_rollover;

        AttractorForceV4() {
            this->m_position = Math::Vector2(450, 300);
            this->m_mass = 30.0f;
            this->m_gravity = 1.0f;
            this->m_dragOffset = false;
            this->m_dragging = false;
            this->m_rollover = false;
        }

        Math::Vector2 calculateAttraction(const ForceV4System& v) {
            // Calculate direction of force
            Math::Vector2 force = m_position - v.m_position;
            // Distance between objects       
            float distance = Math::Vector2::magnitude(force);
            // Limiting the distance to eliminate "extreme" results
            // for very close or very far objects                            
            distance = distance > 5.0f ? (distance < 25.0f ? distance : 25.0f) : 5.0f;
            // Normalize vector                    
            force.normalized();
            // Calculate gravitional force magnitude  
            float strength = (this->m_gravity * this->m_mass * v.m_mass) / (distance * distance);
            // Get force vector --> magnitude * direction
            force = force * strength;
            return force;
        }
    };

    class ForceV4Nature : public INature {
    public:

        inline ForceV4Nature() {
            this->start();
        }

        inline void start() override {
            INature::start();

            this->m_ballTexture = SceneAssets::getTexture("ball");
            this->m_attractorTexture = SceneAssets::getTexture("sun");

            this->m_width = SceneAssets::SCREEN_WIDTH - SceneAssets::LIMIT_WIDTH;
            this->m_height = SceneAssets::SCREEN_HEIGHT - SceneAssets::LIMIT_HEIGHT;

            this->m_attractor = new AttractorForceV4();

            m_natureSystem.clear();

            for (int i = 0; i < m_pItems; i++)
                m_natureSystem.push_back(new ForceV4System((rand() % 25 + 25) / 10.0f,
                    Math::Vector2(20 + i * m_width / m_pItems, 600))
                );
        }

        inline void update() override {
            INature::update();

            for (const auto& it : m_natureSystem) {

                auto force = m_attractor->calculateAttraction(*it);
                it->applyForce(force);
              
                it->update(this->m_width, this->m_height, m_limiteEdge);
            }
        }

        inline void show() override {
            INature::show();
            this->update();
            sprite->draw(m_attractorTexture, Math::Vector2(m_attractor->m_position.x, m_attractor->m_position.y), Math::Vector2(200.0f, 200.0f), 0);
            for (const auto& it : m_natureSystem) {
                sprite->draw(m_ballTexture, Math::Vector2(it->m_position.x, it->m_position.y), Math::Vector2(it->m_mass * m_sizeTexture, it->m_mass * m_sizeTexture), 0);
            }
        }

    private:

        std::vector<ForceV4System*> m_natureSystem;
        AttractorForceV4* m_attractor;

        Texture2D m_ballTexture;
        Texture2D m_attractorTexture;

        int m_width, m_height;
        int m_pItems = 9;

        float m_sizeTexture = 15.0f;
        float m_limiteEdge = 100.0f;

    };
}