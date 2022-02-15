
namespace NatureLab
{
	class INature {
	public:
		inline virtual ~INature() = default;
		inline INature() = default;
		virtual void show() = 0;

	protected:
		
		inline virtual void start() {}
		inline virtual void update() {}

	};
}
