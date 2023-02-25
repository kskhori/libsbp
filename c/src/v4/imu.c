/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/imu.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/imu.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/imu.h>

bool sbp_msg_imu_raw_encode_internal(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_imu_raw_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->tow_f)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->acc_x)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->acc_y)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->acc_z)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->gyr_x)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->gyr_y)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->gyr_z)) {
    return false;
  }
  return true;
}

s8 sbp_msg_imu_raw_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                          const sbp_msg_imu_raw_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_imu_raw_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_imu_raw_decode_internal(sbp_decode_ctx_t *ctx,
                                     sbp_msg_imu_raw_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->tow_f)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->acc_x)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->acc_y)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->acc_z)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->gyr_x)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->gyr_y)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->gyr_z)) {
    return false;
  }
  return true;
}

s8 sbp_msg_imu_raw_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                          sbp_msg_imu_raw_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_imu_raw_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_imu_raw_send(sbp_state_t *s, u16 sender_id,
                        const sbp_msg_imu_raw_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_imu_raw_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_IMU_RAW, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_imu_raw_cmp(const sbp_msg_imu_raw_t *a,
                        const sbp_msg_imu_raw_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->tow_f, &b->tow_f);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->acc_x, &b->acc_x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->acc_y, &b->acc_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->acc_z, &b->acc_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->gyr_x, &b->gyr_x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->gyr_y, &b->gyr_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->gyr_z, &b->gyr_z);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_imu_aux_encode_internal(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_imu_aux_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->imu_type)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->temp)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->imu_conf)) {
    return false;
  }
  return true;
}

s8 sbp_msg_imu_aux_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                          const sbp_msg_imu_aux_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_imu_aux_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_imu_aux_decode_internal(sbp_decode_ctx_t *ctx,
                                     sbp_msg_imu_aux_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->imu_type)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->temp)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->imu_conf)) {
    return false;
  }
  return true;
}

s8 sbp_msg_imu_aux_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                          sbp_msg_imu_aux_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_imu_aux_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_imu_aux_send(sbp_state_t *s, u16 sender_id,
                        const sbp_msg_imu_aux_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_imu_aux_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_IMU_AUX, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_imu_aux_cmp(const sbp_msg_imu_aux_t *a,
                        const sbp_msg_imu_aux_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->imu_type, &b->imu_type);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->temp, &b->temp);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->imu_conf, &b->imu_conf);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
