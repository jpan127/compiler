#pragma once



namespace utils
{

    /// Enumerates the different types of ConstObject
    enum class ConstObjectType
    {
        t_string,
        t_float,
        t_uint,
        t_int,
    };

    /// Abstract base class of generic constant object
    template <class T>
    class ConstObjectBase
    {
    protected:

        /**
         *  Protected constructor
         *  @param type : The type of the object
         */
        ConstObjectBase(const ConstObjectType type) : type(type) { }

        /// Destructor
        virtual ~ ConstObjectBase() { }

        /// Returns the type of the object
        ConstObjectType get_type() const { return type; }

        /**
         *  Returns the value of the object
         *  @note    : To be implemented by derived class
         *  @returns : Value of object
         */
        virtual T get_value() const = 0;

    private:

        /// Type of this object
        const ConstObjectType type;
    };

    /// Derived interface of generic constant object
    template <class T>
    class ConstObject : public ConstObjectBase
    {
    public:

        /**
         *  Constructor
         *  @param type          : Type of this object
         *  @param initial_value : Value of this object
         */
        ConstObject(const ConstObjectType type, T initial_value) : ConstObjectBase(type), value(initial_value) { }

        /**
         *  Gets the value of this object
         *  @returns : The value
         */
        T get_value() const { return value; }

    private:

        const T value;
    };

} /// utils
