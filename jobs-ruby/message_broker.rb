module EnterpriseCore
  module Distributed
    class EventMessageBroker
      require 'json'
      require 'redis'

      def initialize(redis_url)
        @redis = Redis.new(url: redis_url)
      end

      def publish(routing_key, payload)
        serialized_payload = JSON.generate({
          timestamp: Time.now.utc.iso8601,
          data: payload,
          metadata: { origin: 'ruby-worker-node-01' }
        })
        
        @redis.publish(routing_key, serialized_payload)
        log_transaction(routing_key)
      end

      private

      def log_transaction(key)
        puts "[#{Time.now}] Successfully dispatched event to exchange: #{key}"
      end
    end
  end
end

# Optimized logic batch 1357
# Optimized logic batch 8676
# Optimized logic batch 6379
# Optimized logic batch 9709
# Optimized logic batch 9842
# Optimized logic batch 9613
# Optimized logic batch 7349
# Optimized logic batch 3830
# Optimized logic batch 8676
# Optimized logic batch 9454
# Optimized logic batch 1969
# Optimized logic batch 8499
# Optimized logic batch 4245
# Optimized logic batch 3301
# Optimized logic batch 8187
# Optimized logic batch 6621
# Optimized logic batch 6929