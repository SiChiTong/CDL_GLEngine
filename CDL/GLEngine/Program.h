//========================================================================
/** @type     C/C++ Header File
 *  @file     Program.h
 *  @author   acornejo
 *  @date
 *   Created:       12:37:47 21/03/2006
 *   Last Update:   20:41:37 30/05/2007
 */
//========================================================================
#ifndef __GLE_PROGRAM_H__
#define __GLE_PROGRAM_H__

#include <CDL/CDL.h>
#include <vector>

namespace CDL
{
    using CDL::RandomAccessInputStream;
    using CDL::Vec2t;
    using CDL::Vec3t;
    using CDL::Vec4t;

    class Program
    {
        public:
            class Shader
            {
                protected:
                    size_t *m_ref;
                    size_t m_id;

                public:
                    typedef enum {VERTEX,FRAGMENT} Shader_Type;

                    Shader(const Shader_Type &);
                    Shader(const Shader &);
                    virtual ~Shader();
                    const Shader &operator=(const Shader &);
                    void load(RandomAccessInputStream &);
                    string getLog() const;
                    bool isCompiled() const;
                    void compile();

                    friend class Program;
            };

        private:
            size_t *m_ref;
            size_t m_id;
            size_t m_shaderCount;
            std::vector<Shader> m_shader;

        public:
            Program();
            Program(const Program &);
            const Program &operator=(const Program &);
            virtual ~Program();
            void attach(const Shader &);
            const Shader &getShader(const size_t &) const;
            const size_t &getShaderCount() const;
            string getLog() const;
            bool isLinked() const;
            void link();
            void use() const;
            void setUniform(const string &, const int &);
            void setUniform(const string &, const float &);
            void setUniform(const string &, const Vec2t &);
            void setUniform(const string &, const Vec3t &);
            void setUniform(const string &, const Vec4t &);
            static void disable();
    };
}

#endif//__GLE_PROGRAM_H__
