/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2018-2019 Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**

 */

#ifndef NO_SIGNALS_H
#define NO_SIGNALS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifndef EINVAL
#    define EINVAL 22
#endif

/* Frame ids. */
#define NO_SIGNALS_MESSAGE1_FRAME_ID (0x400u)
#define NO_SIGNALS_MESSAGE2_FRAME_ID (0x401u)

/* Frame lengths in bytes. */
#define NO_SIGNALS_MESSAGE1_LENGTH (5u)
#define NO_SIGNALS_MESSAGE2_LENGTH (0u)

/* Extended or standard frame types. */
#define NO_SIGNALS_MESSAGE1_IS_EXTENDED (0)
#define NO_SIGNALS_MESSAGE2_IS_EXTENDED (0)

/* Frame cycle times in milliseconds. */


/* Signal choices. */


/* Frame Names. */
#define NO_SIGNALS_MESSAGE1_NAME "Message1"
#define NO_SIGNALS_MESSAGE2_NAME "Message2"

/* Signal Names. */


/**
 * Signals in message Message1.
 *
 * All signal values are as on the CAN bus.
 */
typedef struct {
    /**
     * Dummy signal in empty message.
     */
    uint8_t dummy;
} no_signals_message1;

/**
 * Signals in message Message2.
 *
 * All signal values are as on the CAN bus.
 */
typedef struct {
    /**
     * Dummy signal in empty message.
     */
    uint8_t dummy;
} no_signals_message2;

/**
 * Pack message Message1.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int no_signals_message1_pack(
    uint8_t *dst_p,
    const no_signals_message1 *src_p,
    size_t size);

/**
 * Unpack message Message1.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int no_signals_message1_unpack(
    no_signals_message1 *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Check that all signals in the given message are are in the allowed range.
 *
 * @param[in] value Message to check.
 *
 * @return true if all values are in range, false otherwise.
 */
bool no_signals_message1_is_in_range(no_signals_message1 value);

/**
 * Init message fields to default values from Message1.
 *
 * @param[in] msg_p Message to init.
 *
 * @return zero(0) on success or (-1) in case of nullptr argument.
 */
int no_signals_message1_init(no_signals_message1 *msg_p);

/**
 * Pack message Message2.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int no_signals_message2_pack(
    uint8_t *dst_p,
    const no_signals_message2 *src_p,
    size_t size);

/**
 * Unpack message Message2.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int no_signals_message2_unpack(
    no_signals_message2 *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Check that all signals in the given message are are in the allowed range.
 *
 * @param[in] value Message to check.
 *
 * @return true if all values are in range, false otherwise.
 */
bool no_signals_message2_is_in_range(no_signals_message2 value);

/**
 * Init message fields to default values from Message2.
 *
 * @param[in] msg_p Message to init.
 *
 * @return zero(0) on success or (-1) in case of nullptr argument.
 */
int no_signals_message2_init(no_signals_message2 *msg_p);


#ifdef __cplusplus
}
#endif

#endif
