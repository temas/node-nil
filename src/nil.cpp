#include <v8.h>
#include <node.h>

using namespace v8;
using namespace node;

namespace nil { 

static Persistent<ObjectTemplate> object_template_;
static Persistent<Value> nil_instance_;

static Handle<Value> ObjectGet(Local<String> name, const AccessorInfo& info)
{
    HandleScope handle_scope;
    return handle_scope.Close(info.Holder());
}

static Handle<Value> ObjectSet(Local<String> name, Local<Value> value_obj, const AccessorInfo& info)
{
    HandleScope handle_scope;
    return handle_scope.Close(info.Holder());
}

static Handle<Integer> ObjectQuery(Local<String> property, const AccessorInfo &info)
{
    HandleScope handle_scope;
    return handle_scope.Close(Integer::New(v8::None));
}

static Handle<Boolean> ObjectDeleter(Local< String > property, const AccessorInfo &info)
{
    HandleScope handle_scope;
    return handle_scope.Close(v8::False());
}

static Handle<Array> ObjectEnum(const AccessorInfo &info)
{
    HandleScope handle_scope;
    return handle_scope.Close(Array::New());
}

static Handle<ObjectTemplate> PrepareTemplate()
{
    HandleScope handle_scope;

    Handle<ObjectTemplate> result = ObjectTemplate::New();
    result->SetInternalFieldCount(1);
    result->SetNamedPropertyHandler(ObjectGet, ObjectSet, ObjectQuery, ObjectDeleter, ObjectEnum);

    return handle_scope.Close(result);
}

static Handle<Value> Nil(const Arguments& args)
{
    HandleScope handle_scope;

    if (object_template_.IsEmpty()) {
        Handle<ObjectTemplate> raw_template = PrepareTemplate();
        object_template_ = Persistent<ObjectTemplate>::New(raw_template);
    }

    if (nil_instance_.IsEmpty()) {
        nil_instance_ = Persistent<Value>::New(object_template_->NewInstance());
    }
    
    return handle_scope.Close(nil_instance_);
}

}; // namespace nil 

extern "C" {

static void init(Handle<Object> target)
{
    HandleScope scope;
    NODE_SET_METHOD(target, "Nil", nil::Nil);
    //target = nil::Nil();
}

NODE_MODULE(nil, init);
}
