#ifndef MA_API_MUTEX_H
#define MA_API_MUTEX_H

namespace ftn
{
    namespace mikesapi
    {
        namespace samplecode
        {
            // A very simple mutex class for sample code purposes. 
            // It is recommended that you use the boost threads library.
            class Mutex
            {
            public:
                Mutex()
                {
                    if (!InitializeCriticalSectionAndSpinCount(&_cs,0x80000400)) 
                    {
                        throw std::runtime_error("Failed to initialize Mutex");
                    }
                }
                ~Mutex()
                {
                    DeleteCriticalSection(&_cs);
                }
                void lock() const
                {
                    EnterCriticalSection(&_cs); 
                }
                void unlock() const
                {
                    LeaveCriticalSection(&_cs); 
                }
            private:
                // Noncopyable
                Mutex(const Mutex &);
                Mutex &operator=(const Mutex &);
            private:
                mutable CRITICAL_SECTION _cs;
            };
        }
    }
}
#endif
