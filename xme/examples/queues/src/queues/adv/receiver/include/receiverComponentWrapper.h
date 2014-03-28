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
 * $Id: receiverComponentWrapper.h 7769 2014-03-11 15:27:13Z geisinger $
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

#ifndef QUEUES_ADV_RECEIVER_RECEIVERCOMPONENTWRAPPER_H
#define QUEUES_ADV_RECEIVER_RECEIVERCOMPONENTWRAPPER_H

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "xme/core/executionManager/include/executionManagerDataStructures.h"

#include "queues/topic/dictionaryData.h"

/******************************************************************************/
/***   Type definitions                                                     ***/
/******************************************************************************/

/**
 * \enum queues_adv_receiver_receiverComponentWrapper_internalFunctionId_e
 *
 * \brief Values for identifying functions of receiver component.
 */
enum queues_adv_receiver_receiverComponentWrapper_internalFunctionId_e
{
    QUEUES_ADV_RECEIVER_RECEIVERCOMPONENTWRAPPER_FUNCTION_RECEIVE = 0  ///< Function 'receive'
};

/**
 * \enum queues_adv_receiver_receiverComponentWrapper_internalPortId_e
 *
 * \brief Values for queues_adv_receiver_receiverComponentWrapper_internalPortId_t.
 */
enum queues_adv_receiver_receiverComponentWrapper_internalPortId_e
{
    QUEUES_ADV_RECEIVER_RECEIVERCOMPONENTWRAPPER_PORT_IN = 0  ///< Port 'in'
};

/**
 * \typedef queues_adv_receiver_receiverComponentWrapper_internalPortId_t
 *
 * \brief Defines internal port ids of component 'receiver'.
 *
 * \details These can be used when calling the queues_adv_receiver_receiverComponentWrapper_receivePort function.
 *          For the definition of possible values, see enum queues_adv_receiver_receiverComponentWrapper_internalPortId_e.
 */
typedef uint8_t queues_adv_receiver_receiverComponentWrapper_internalPortId_t;

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
queues_adv_receiver_receiverComponentWrapper_init(void);

/**
 * \brief Finalizes this component wrapper.
 */
void
queues_adv_receiver_receiverComponentWrapper_fini(void);

/**
 * \brief Associate an internal port number with the corresponding port handle.
 *        For the ids of the individual ports, see the definition of queues_adv_receiver_receiverComponentWrapper_internalPortId_t.
 *
 * \param dataPacketId Port handle from the dataHandler.
 * \param componentInternalPortId Component internal port number of the above port.
 *
 * \retval XME_STATUS_SUCCESS if no problems occurred.
 * \retval XME_STATUS_INVALID_PARAMETER if componentInternalPortId is unknown.
 */
xme_status_t
queues_adv_receiver_receiverComponentWrapper_receivePort
(
    xme_core_dataManager_dataPacketId_t dataPacketId,
    queues_adv_receiver_receiverComponentWrapper_internalPortId_t componentInternalPortId
);

/**
 * \brief This function is called by the function wrapper after the step
 *        function has been called. It signals to the middleware that all
 *        input ports have been read.
 */
void
queues_adv_receiver_receiverComponentWrapper_completeReadOperations(void);

/**
 * \brief Read data from port 'in'.
 *
 * \param[out] data User provided storage, to which the data is copied.
 *
 * \retval XME_STATUS_SUCCESS if reading was successful.
 * \retval XME_STATUS_NO_SUCH_VALUE when there is now new data on this port
 *         (only possible when this port is an optional port of the current function).
 * \retval XME_STATUS_INVALID_PARAMETER if data is NULL.
 * \retval XME_STATUS_INTERNAL_ERROR in case of any other error.
 */
xme_status_t
queues_adv_receiver_receiverComponentWrapper_readPortIn
(
    const queues_topic_data_t* data
);

xme_status_t
queues_adv_receiver_receiverComponentWrapper_readInputPortAttribute
(
    queues_adv_receiver_receiverComponentWrapper_internalPortId_t portId,
    xme_core_attribute_key_t attributeKey,
    void* const buffer,
    uint32_t bufferSize
);

xme_status_t
queues_adv_receiver_receiverComponentWrapper_readNextPacket
(
    queues_adv_receiver_receiverComponentWrapper_internalPortId_t portId
);


XME_EXTERN_C_END

#endif // #ifndef QUEUES_ADV_RECEIVER_RECEIVERCOMPONENTWRAPPER_H
