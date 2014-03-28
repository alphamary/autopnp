/*
 * Copyright (c) 2011-2014, fortiss GmbH.
 * Licensed under the Apache License, Version 2.0.
 *
 * Use, modification and distribution are subject to the terms specified
 * in the accompanying license file LICENSE.txt located at the root directory
 * of this software distribution. A copy is available at
 * http://chromosome.fortiss.org/.
 *
 * This file is part of CHROMOSOME.
 *
 * $Id$
 */

/**
 * \file
 *         Component wrapper - implements interface of a component
 *              to the data handler
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

#ifndef AUTOPNP_ADV_EXAMPLEGUI_EXAMPLEGUICOMPONENTWRAPPER_H
#define AUTOPNP_ADV_EXAMPLEGUI_EXAMPLEGUICOMPONENTWRAPPER_H

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "xme/core/executionManager/include/executionManagerDataStructures.h"

#include "xme/core/topicData.h"
#include "autoPnP/topic/AutoPnPCommonData.h"

/******************************************************************************/
/***   Type definitions                                                     ***/
/******************************************************************************/

/**
 * \enum autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_internalFunctionId_e
 *
 * \brief Values for identifying functions of exampleGUI component.
 */
enum autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_internalFunctionId_e
{
    AUTOPNP_ADV_EXAMPLEGUI_EXAMPLEGUICOMPONENTWRAPPER_FUNCTION_DOSOMETHING = 0  ///< Function 'doSomething'
};

/**
 * \enum autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_internalPortId_e
 *
 * \brief Values for autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_internalPortId_t.
 */
enum autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_internalPortId_e
{
    AUTOPNP_ADV_EXAMPLEGUI_EXAMPLEGUICOMPONENTWRAPPER_PORT_ADDCOMPONENT = 0, ///< Port 'addComponent'
    AUTOPNP_ADV_EXAMPLEGUI_EXAMPLEGUICOMPONENTWRAPPER_PORT_REMOVECOMPONENT = 1  ///< Port 'removeComponent'
};

/**
 * \typedef autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_internalPortId_t
 *
 * \brief Defines internal port ids of component 'exampleGUI'.
 *
 * \details These can be used when calling the autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_receivePort function.
 *          For the definition of possible values, see enum autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_internalPortId_e.
 */
typedef uint8_t autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_internalPortId_t;

/******************************************************************************/
/***   Prototypes                                                           ***/
/******************************************************************************/
XME_EXTERN_C_BEGIN

/**
 * \brief Initializes this component wrapper.
 *
 * \retval XME_STATUS_SUCCESS on success.
 */
xme_status_t
autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_init(void);

/**
 * \brief Finalizes this component wrapper.
 */
void
autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_fini(void);

/**
 * \brief Associate an internal port number with the corresponding port handle.
 *        For the ids of the individual ports, see the definition of autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_internalPortId_t.
 *
 * \param dataPacketId Port handle from the dataHandler.
 * \param componentInternalPortId Component internal port number of the above port.
 *
 * \retval XME_STATUS_SUCCESS if no problems occurred.
 * \retval XME_STATUS_INVALID_PARAMETER if componentInternalPortId is unknown.
 */
xme_status_t
autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_receivePort
(
    xme_core_dataManager_dataPacketId_t dataPacketId,
    autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_internalPortId_t componentInternalPortId
);

/**
 * \brief This function is called by the function wrapper after the step
 *        function has been called. It signals to the middleware that all
 *        write operations on ports that actually have been written to
 *        in the step function (via the functions in this component wrapper)
 *        are now completed.
 */
void
autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_completeWriteOperations(void);

/**
 * \brief Write data to port 'addComponent'.
 *
 * \note The write operation is only allowed to be called once per
 *       data packet sending process. A data packet is sent 
 *       as soon as the autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_writeNextPacket()
 *       function is being called or when the step function
 *       returns and data have been written.
 * 
 * \param[in] data User provided storage, from which the data is copied.
 *            When NULL no data will be written to the port (this
 *            is also treated as  success).
 *
 * \retval XME_STATUS_SUCCESS if operation was successful.
 */
xme_status_t
autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_writePortAddComponent
(
    const AutoPnP_topic_add_component_t* const data
);

/**
 * \brief Write data to port 'removeComponent'.
 *
 * \note The write operation is only allowed to be called once per
 *       data packet sending process. A data packet is sent 
 *       as soon as the autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_writeNextPacket()
 *       function is being called or when the step function
 *       returns and data have been written.
 * 
 * \param[in] data User provided storage, from which the data is copied.
 *            When NULL no data will be written to the port (this
 *            is also treated as  success).
 *
 * \retval XME_STATUS_SUCCESS if operation was successful.
 */
xme_status_t
autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_writePortRemoveComponent
(
    const AutoPnP_topic_remove_component_t* const data
);

xme_status_t
autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_writeOutputPortAttribute
(
    autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_internalPortId_t portId,
    xme_core_attribute_key_t attributeKey,
    const void* const buffer,
    uint32_t bufferSize
);

xme_status_t
autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_writeNextPacket
(
    autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_internalPortId_t portId
);


XME_EXTERN_C_END

#endif // #ifndef AUTOPNP_ADV_EXAMPLEGUI_EXAMPLEGUICOMPONENTWRAPPER_H
