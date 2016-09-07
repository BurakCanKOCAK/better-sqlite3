// .run(Function callback) -> this

NAN_METHOD(Transaction::Run) {
	Transaction* trans = Nan::ObjectWrap::Unwrap<Transaction>(info.This());
	REQUIRE_LAST_ARGUMENT_FUNCTION(func_index, func);
	WORKER_START(trans, info, func_index, TRANSACTION_BIND, transaction);
	TransactionWorker* worker = new TransactionWorker(trans, new Nan::Callback(func));
	WORKER_END(trans, worker);
}