#ifndef ONEFLOW_CORE_OPERATOR_SPARSE_CROSS_ENTROPY_OP_H_
#define ONEFLOW_CORE_OPERATOR_SPARSE_CROSS_ENTROPY_OP_H_

#include "oneflow/core/operator/operator.h"

namespace oneflow {

class SparseCrossEntropyOp final : public Operator {
 public:
  OF_DISALLOW_COPY_AND_MOVE(SparseCrossEntropyOp);
  SparseCrossEntropyOp() = default;
  ~SparseCrossEntropyOp() override = default;

  void InitFromOpConf() override;
  const PbMessage& GetCustomizedConf() const override;
  Maybe<void> InferBlobDescs(std::function<BlobDesc*(const std::string&)> GetBlobDesc4BnInOp,
                             const ParallelContext* parallel_ctx, const SbpSignature* sbp_signature,
                             std::function<void(OpContext*)> EnrollOpCtx) const override;

 private:
  Maybe<void> InferBatchAxis(
      std::function<OptInt64*(const std::string&)> BatchAxis4BnInOp) const override {
    return NaiveInferBatchAxis(BatchAxis4BnInOp);
  }

  Maybe<void> GetSbpSignatures(SbpSignatureList* sbp_sig_list) const override;
};

}  // namespace oneflow

#endif  // ONEFLOW_CORE_OPERATOR_SPARSE_CROSS_ENTROPY_OP_H_