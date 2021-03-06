//------------------------------------------------------------
// Declaration: Copyright (c), by i_dovelemon, 2017. All right reserved.
// Author: i_dovelemon[1322600812@qq.com]
// Date: 2017/05/25
// Brief: Script component update entity's AI
//------------------------------------------------------------
#include "scriptcom.h"

#include <memory>

#include "entity.h"
#include "../pyscript/pyscriptmgr.h"

namespace entity {

ScriptCom::ScriptCom(Entity* owner, const char* file)
: Component(CT_SCRIPT, owner) {
    int32_t len = strlen(file);
    len = (len > kScriptFileNameMaxLen - 1) ? (kScriptFileNameMaxLen - 1) : len;
    memcpy(m_ScriptFile, file, len);
    m_ScriptFile[len] = '\0';

    pyscript::PyScriptMgr::LoadScript(m_ScriptFile);
}

ScriptCom::~ScriptCom() {
}

void ScriptCom::Update(float dt) {
    pyscript::PyScriptMgr::RunScript(m_ScriptFile, m_Entity->GetID());
}

};  // namespace entity